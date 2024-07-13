import java.util.Scanner;

public class Tournament {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of teams (2-4): ");
        int numTeams = scanner.nextInt();
        
        if (numTeams < 2 || numTeams > 4) {
            System.out.println("Invalid number of teams. Please run the program again.");
            return ;
        }
        
        String[] teams = new String[numTeams];
        
        for (int i = 0; i < numTeams; i++) {
            System.out.print("Enter name for team " + (i + 1) + ": ");
            teams[i] = scanner.next();
        }
        
        System.out.println("\nTeams in the tournament:");
        int teamNumber = 1;
        while (teamNumber <= numTeams) {
            System.out.println(teamNumber + ". " + teams[teamNumber - 1]);
            teamNumber++;
        }
        
        System.out.println("\nMatches between the teams!");
        
        for (int i = 0; i < numTeams - 1; i++) {
            for (int j = i + 1; j < numTeams; j++) {
            String team1 = teams[i];
            String team2 = teams[j];
            System.out.println(team1 + " vs " + team2);
            
            if (Math.random() < 0.5) {
                System.out.println(team1 + " wins!");
            } else {
                System.out.println(team2 + " wins!");
            }
            }
        }
        scanner.close();
    }
}