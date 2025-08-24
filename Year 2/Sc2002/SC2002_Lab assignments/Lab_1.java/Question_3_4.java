import java.util.Scanner;

public class Question_3_4 {
	
		public static void main(String[] args) {
		        Scanner sc = new Scanner(System.in);

		        System.out.print("Enter the height: ");
		        int height = sc.nextInt();

		        if (height < 1) {
		            System.out.println("Error input!");
		        } else {
		            for (int i = 1; i <= height; i++) {
		                for (int j = 1; j <= i; j++) {
		                	if(i%2==1) {
		                    if (j % 2 == 1) {
		                        System.out.print("AA");
		                    } else {
		                        System.out.print("BB");
		                    }
		                }
		                	else {
		                		 if (j % 2 == 1) {
		 	                        System.out.print("BB");
		 	                    } else {
		 	                        System.out.print("AA");
		 	                    }}
		                }
		                	
		                	
		              System.out.println(); // Move this line outside of the inner loop
		            }
		        }
		    }
		}