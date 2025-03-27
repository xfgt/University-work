package org.example.hard;

import java.util.HashMap;
import java.util.Map;

public class UserManager {
    private Map<String, String> users = new HashMap<>();

    public void registerUser(String username, String password) {
        if (!validateUsername(username)) {
            throw new IllegalArgumentException("Invalid username. Must be at least 3 characters.");
        }
        if (validatePassword(password)) {
            throw new IllegalArgumentException("Invalid password. Must be at least 6 characters.");
        }
        if (users.containsKey(username)) {
            throw new IllegalArgumentException("Username already exists.");
        }
        users.put(username, hashPassword(password));
    }

    public boolean loginUser(String username, String password) {
        if (!users.containsKey(username)) {
            throw new IllegalArgumentException("User does not exist.");
        }
        String storedHash = users.get(username);
        return storedHash.equals(hashPassword(password));
    }

    public void changePassword(String username, String oldPassword, String newPassword) {
        if (!loginUser(username, oldPassword)) {
            throw new IllegalArgumentException("Old password is incorrect.");
        }
        if (validatePassword(newPassword)) {
            throw new IllegalArgumentException("New password is invalid. Must be at least 6 characters.");
        }
        users.put(username, hashPassword(newPassword));
    }

    public void deleteUser(String username) {
        if (!users.containsKey(username)) {
            throw new IllegalArgumentException("User does not exist.");
        }
        users.remove(username);
    }

    public String getUserInfo(String username) {
        if (!users.containsKey(username)) {
            throw new IllegalArgumentException("User does not exist.");
        }
        return "Username: " + username + ", Password Hash: " + users.get(username);
    }

    private boolean validateUsername(String username) {
        return username != null && username.trim().length() >= 3;
    }

    private boolean validatePassword(String password) {
        return password == null || password.length() < 6;
    }

    private String hashPassword(String password) {
        return Integer.toString(password.hashCode());
    }
}

