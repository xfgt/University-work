package org.example.easy;

public class StringUtils {

    public String reverse(String input) {
        return new StringBuilder(input).reverse().toString();
    }

    public boolean isPalindrome(String input) {
        String cleaned = input.replaceAll("\\s+", "").toLowerCase();
        return cleaned.contentEquals(new StringBuilder(cleaned).reverse());
    }

    public int countVowels(String input) {
        int count = 0;
        for (char ch : input.toLowerCase().toCharArray()) {
            if ("aeiou".indexOf(ch) != -1) {
                count++;
            }
        }
        return count;
    }

    public String toTitleCase(String input) {
        String[] words = input.split("\\s+");
        StringBuilder titleCase = new StringBuilder();
        for (String word : words) {
            if (!word.isEmpty()) {
                titleCase.append(Character.toUpperCase(word.charAt(0)))
                        .append(word.substring(1).toLowerCase())
                        .append(" ");
            }
        }
        return titleCase.toString().trim();
    }

    public String removeSpaces(String input) {
        return input.replaceAll("\\s+", "");
    }
}

