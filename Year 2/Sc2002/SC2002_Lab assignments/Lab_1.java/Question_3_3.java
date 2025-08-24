import java.util.Scanner;

public class Question_3_3 {
	

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		//1 US dollar(US$) = 1.82 Singapore dollars (S$)
		
		System.out.println(" starting:");
		int starting_value = sc.nextInt();
		
		System.out.println("ending:");
		int ending_value=sc.nextInt();
		
		System.out.println("increment:");
		int increment= sc.nextInt();
		
		//1 US dollar(US$) = 1.82 Singapore dollars (S$)
		System.out.println("enter your choice");
		int choice=sc.nextInt();
		System.out.println("US$          S$\n------------------- ");
		switch(choice) {
		case 1:
		//1. Use a for loop to generate the first table;
		System.out.println("using for loop:");	
		
		for(increment=starting_value;increment<=ending_value;increment++) {
			
			double US$=increment * 1.82;
			System.out.println(increment+ "     " + US$);
			
			} break;
			
		case 2:
		
		//2. Use a while loop to generate the second table; 
			System.out.println("using while loop:");
			int current =starting_value;
		while(current<=ending_value) {
			
			double US$=current * 1.82;
			System.out.println(current+ "     " + US$);
			current+=increment;
		}
		 break;
		
		case 3:
		//3. Use a do/while loop to generate the third table.
			System.out.println("using do while loop:");
			int current2=starting_value;
		do { 
		
			double US$=current2 * 1.82;
			System.out.println(current2+ "     " + US$);
			current2+=increment;}
		 while(current2<=ending_value);
		System.out.println("Error Input!");
		}		
}
}
