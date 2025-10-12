//
// Created by LOCAL_ADMIN on 12.10.2025 г..
//
// Add to BoxWithToys-and-Fstream.cpp (or a new .cpp)
// Requires: <cstdint>, <fstream>, <vector>, <set>, <string>

#include "Box.h"
#include <cstdint>
#include <fstream>
#include <vector>
#include <set>
#include <string>

namespace binio {

// --- helpers for strings ---
static void write_string(std::ostream& os, const std::string& s) {
    const std::uint64_t len = static_cast<std::uint64_t>(s.size());
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(s.data(), static_cast<std::streamsize>(len));
    if (!os) throw std::runtime_error("write_string failed");
}

static std::string read_string(std::istream& is) {
    std::uint64_t len = 0;
    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!is) throw std::runtime_error("read_string length failed");
    std::string s;
    s.resize(static_cast<size_t>(len));
    if (len) is.read(&s[0], static_cast<std::streamsize>(len));
    if (!is) throw std::runtime_error("read_string data failed");
    return s;
}

// --- Box (de)serialization using Box's public API ---
static void write_box(std::ostream& os, const Box& b) {
    write_string(os, b.getName());
    const std::uint8_t taped = b.hasTape() ? 1u : 0u;
    os.write(reinterpret_cast<const char*>(&taped), sizeof(taped));

    const auto toys = b.getToysCollection(); // copy is fine
    const std::uint64_t count = static_cast<std::uint64_t>(toys.size());
    os.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (const auto& t : toys) write_string(os, t);
    if (!os) throw std::runtime_error("write_box failed");
}

static Box* read_box(std::istream& is) {
    const std::string name = read_string(is);
    std::uint8_t taped = 0;
    is.read(reinterpret_cast<char*>(&taped), sizeof(taped));
    if (!is) throw std::runtime_error("read_box tape flag failed");

    std::uint64_t count = 0;
    is.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (!is) throw std::runtime_error("read_box toy count failed");

    std::set<std::string> toys;
    for (std::uint64_t i = 0; i < count; ++i) {
        toys.insert(read_string(is));
    }

    // Rebuild Box using your API. b_ID is set by the constructor. :contentReference[oaicite:2]{index=2}
    Box* b = new Box(name, taped != 0);
    if (!toys.empty()) b->fillWithToys(toys);
    return b;
}

// --- Vector<Box*> (de)serialization ---
static void save_boxes(const std::string& path, const std::vector<Box*>& boxes) {
    std::ofstream os(path, std::ios::binary);
    if (!os) throw std::runtime_error("Cannot open for write: " + path);

    const std::uint64_t n = static_cast<std::uint64_t>(boxes.size());
    os.write(reinterpret_cast<const char*>(&n), sizeof(n)); // sizeof(n) is critical
    for (const Box* b : boxes) write_box(os, *b);
}

static std::vector<Box*> load_boxes(const std::string& path) {
    std::ifstream is(path, std::ios::binary);
    if (!is) throw std::runtime_error("Cannot open for read: " + path);

    std::uint64_t n = 0;
    is.read(reinterpret_cast<char*>(&n), sizeof(n));
    if (!is) throw std::runtime_error("Failed to read box count");

    std::vector<Box*> out;
    out.reserve(static_cast<size_t>(n));
    for (std::uint64_t i = 0; i < n; ++i) {
        out.push_back(read_box(is));
    }
    return out;
}

} // namespace binio
