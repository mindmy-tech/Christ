import java.util.Scanner;

public class IncomeTaxCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of employees: ");
        int numberOfEmployees = sc.nextInt();
        sc.nextLine();  // Consume the newline character

        for (int i = 0; i < numberOfEmployees; i++) {
            System.out.print("Enter Employee Name: ");
            String empName = sc.nextLine();

            System.out.print("Enter Designation: ");
            String designation = sc.nextLine();

            System.out.print("Enter Department: ");
            String department = sc.nextLine();

            System.out.print("Enter BASIC SALARY: ");
            double basicSalary = sc.nextDouble();

            double da = basicSalary * 0.12;
            double hra = basicSalary * 0.15;

            double grossSalary = basicSalary + da + hra;
            double annualSalary = grossSalary * 12;



            double tax_amount = calculateTax(annualSalary);
            // double tax = annualSalary - tax_amount;

            double netAnnualSalary = annualSalary - tax_amount;
            double monthlyTaxDeduction = tax_amount / 12;
            double netMonthlySalary = grossSalary - monthlyTaxDeduction;

            System.out.println("\nEmployee Details:");
            System.out.println("Name: " + empName);
            System.out.println("Designation: " + designation);
            System.out.println("Department: " + department);
            System.out.println("Basic Salary: " + basicSalary);
            System.out.println("Dearness Allowance: " + da);
            System.out.println("House Rent Allowance: " + hra);
            System.out.println("Gross Salary per Month: " + grossSalary);
            System.out.println("Yearly/Annual Income: " + annualSalary);
            System.out.println("Total Tax to be Paid: " + tax_amount);
            System.out.println("Monthly Tax Deduction: " + monthlyTaxDeduction);
            System.out.println("Net Monthly Salary: " + netMonthlySalary);
            System.out.println("Net Annual Salary: " + netAnnualSalary);
            System.out.println();

        }

        sc.close();
    }

    public static double calculateTax(double annualSalary) {
        double tax = 0;

        if (annualSalary > 1500000) {
            tax = annualSalary * .30;
        } else if (annualSalary > 1200000) {
            tax = annualSalary * .20;
        } else if (annualSalary > 900000) {
            tax = annualSalary * .15;
        } else if (annualSalary > 600000) {
            tax = annualSalary * .10;
        } else if (annualSalary > 300000) {
            tax = annualSalary * .05;
        }
        return tax;
    }
}
