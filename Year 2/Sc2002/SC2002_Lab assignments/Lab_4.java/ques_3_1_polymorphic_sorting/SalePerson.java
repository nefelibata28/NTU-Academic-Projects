package ques_3_1_polymorphic_sorting;
public class SalePerson implements Comparable<SalePerson> {
    private String firstName;
    private String lastName;
    private int totalSales;

    // Constructor
    public SalePerson(String firstName, String lastName, int totalSales) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }

    // Getter methods for first name, last name, and total sales
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getTotalSales() {
        return totalSales;
    }

    // toString method
    //Override
    public String toString() {
        return lastName + ", " + firstName + " : " + totalSales;
    }

    // equals method
    //Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        SalePerson other = (SalePerson) obj;
        return firstName.equals(other.firstName) && lastName.equals(other.lastName);
    }

    // compareTo method for sorting based on total sales and last name
    //Override
    public int compareTo(SalePerson other) {
        int salesComparison = Integer.compare(this.totalSales, other.totalSales);
        if (salesComparison == 0) {
            return this.lastName.compareTo(other.lastName);
        }
        return salesComparison;
    }
}
