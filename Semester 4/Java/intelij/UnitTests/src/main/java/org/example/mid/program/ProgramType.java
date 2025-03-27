package org.example.mid.program;

public enum ProgramType {
    MAJOR(240), MINOR(120);
    private int credits;

    ProgramType(int credits) {
        this.credits = credits;
    }

    public int getCredits() {
        return credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }
}
