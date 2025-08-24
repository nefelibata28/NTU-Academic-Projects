import java.util.Scanner;

public class Question3_2 {
	
public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		
		System.out.println(" salary:");
		int salary= sc.nextInt();
		
		System.out.println("merit");
		int merit=sc.nextInt();
		
		if (salary >= 500 && salary < 600)
            System.out.print("Grade C\n");
		
        else if (salary >= 600 && salary <= 649) {
            if (merit < 10)
                System.out.print("Grade C\n");
            else
                System.out.print("Grade B\n");
        } 
        
        else if (salary > 649 && salary < 700)
            System.out.print("Grade B\n");
		
		
		
        else if(salary>=700 && salary<=799) {
			if(merit<20) {
				System.out.println("Grade B");
			}
			else {
			System.out.println(" Grade A ");
		}}
		
		
			
		else {
			System.out.println("Grade A");
			}
	
		}

}
