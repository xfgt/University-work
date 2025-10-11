-- Drop if exists
DROP TABLE IF EXISTS Loans, Books, Authors, Members, Categories;

-- Authors Table
CREATE TABLE Authors (
    author_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    country VARCHAR(50),
    birth_year YEAR,
    awards TEXT,
    active BOOLEAN DEFAULT TRUE
);

-- Categories Table
CREATE TABLE Categories (
    category_id INT AUTO_INCREMENT PRIMARY KEY,
    category_name VARCHAR(50) NOT NULL UNIQUE,
    description TEXT
);

-- Books Table
CREATE TABLE Books (
    book_id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(150) NOT NULL,
    author_id INT,
    category_id INT,
    isbn VARCHAR(20) UNIQUE,
    published_year YEAR,
    pages INT,
    rating DECIMAL(2,1),
    language VARCHAR(50),
    available_copies INT DEFAULT 0,
    added_to_library DATE,
    FOREIGN KEY (author_id) REFERENCES Authors(author_id),
    FOREIGN KEY (category_id) REFERENCES Categories(category_id)
);

-- Members Table
CREATE TABLE Members (
    member_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    join_date DATE NOT NULL,
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(20),
    dob DATE,
    address TEXT,
    membership_type ENUM('Standard', 'Premium', 'Student') DEFAULT 'Standard',
    fines_due DECIMAL(6,2) DEFAULT 0.00
);

-- Loans Table
CREATE TABLE Loans (
    loan_id INT AUTO_INCREMENT PRIMARY KEY,
    book_id INT,
    member_id INT,
    loan_date DATE NOT NULL,
    due_date DATE,
    return_date DATE,
    renewals INT DEFAULT 0,
    late_fee DECIMAL(5,2) DEFAULT 0.00,
    FOREIGN KEY (book_id) REFERENCES Books(book_id),
    FOREIGN KEY (member_id) REFERENCES Members(member_id)
);
