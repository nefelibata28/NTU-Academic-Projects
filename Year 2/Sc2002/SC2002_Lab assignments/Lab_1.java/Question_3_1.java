//question 3.1
import java.util.Scanner;


public class Question_3_1 {
 
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("enter the character:");
		char choice = sc.next().charAt(0);
		
		switch(choice) {
		
		case 'a':
		case 'A':
				System.out.println("Action movie fan\n");
		        break;
		case 'c':  
		case 'C': 
		    	System.out.println("Comedy movie fan\n");
		        break;
		case 'd':    
		case 'D':
		    	System.out.println("Drama movie fan\n");
		        break;
		    
		 default:
		    	System.out.println("Invalid choice\n");
				
		}	
		
	}
}
