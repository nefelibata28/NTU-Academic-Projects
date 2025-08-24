import java.util.Scanner;


public class Lab2 {
		public static void main(String[] args) {
			int choice;
			Scanner sc = new Scanner(System.in);
			do{
				    	System.out.println("perform the following methods:");
				        System.out.println("1: multiplication test");
				        System.out.println("2: quotient using division by subtraction");
				        System.out.println("3: remainder using division by subtraction");
				        System.out.println("4: count the number of digits:");
				        System.out.println("5: position of a digit");
				        System.out.println("6: extract all odd digits");
				        System.out.println("7: quit");
				        
				        int m,n;
				        choice=sc.nextInt();
				        switch(choice){
				        	case 1:
				        		mulTest();
				        		break;
				        	case 2:
				        		System.out.println("m=");
							    m=sc.nextInt();
							    System.out.println("n=");
							    n=sc.nextInt();
							    System.out.println("Quotient:"+divide(m,n));
							    break;
				        	case 3: 
				        		System.out.println("m=");
						        m=sc.nextInt();
						        System.out.println("n=");
						        n=sc.nextInt();
						        System.out.println("Remainder:"+modulus(m,n));
				        		break;
				        	case 4: 
				        		System.out.println("n=");
							    n=sc.nextInt();
							    System.out.println("Number of digits: " + countDigits(n));
				                break;
				        	case 5:
				        		 int digit=0;
							     System.out.println("the number  is:");
							     n=sc.nextInt();
							     System.out.println("the digit  is:");
							     digit=sc.nextInt();
							     int position = position(n, digit);
				                 if (position == -1) {
				                	 System.out.println("Digit not found.");
				                 } else {
				                     System.out.println("Position: " + position);
				                    }
				        		break;
				        	case 6: 
				        		long num=0;
								System.out.printf("num=");
								num=sc.nextLong();
								long result = extractOddDigits(num);
			                    if (result == -1) {
			                        System.out.println("No odd digits found.");
			                    } else {
			                        System.out.println("Odd Digits: " + result);
			                    }
				        		break;
				            case 7: System.out.println("Program terminating");
				                break;
				           }
				        }while(choice<7);
			        sc.close();
				    }


	//question 3.2 Multiplication  
				
				public static void mulTest(){
				        Scanner sc = new Scanner(System.in);
				        int count=0;
				        int useranswer=0;
				        int num1=0,num2=0;
				        int correctanswer=0;
				        
				   
				        for(int i=0;i<5;i++){ // a loop to run 5 times
				        num1=(int)(Math.random()*10)+1;
				        num2=(int)(Math.random()*10)+1;
				        correctanswer= num1*num2;
				       
				        System.out.printf("How much is %d times %d ?\n", num1, num2);
				        useranswer=sc.nextInt();
				    
				        if(correctanswer==useranswer) {
				             count++; }
				        }
				        System.out.printf("%d answers out of 5 are correct\n", count);
				      //  sc.close();
				        }
				
				
				        
	//question 3.3 Divide
				public static int divide(int m, int n){ 
					int quotient=0;
					
				     while (m >= n) {
				            m -= n;
				            quotient++;
				        }
				       return quotient;
				       
				  //  System.out.println(m+"/"+n+"="+quotient) ; 
				    }


	//question 3.4 Modulus
				public static int modulus(int m, int n){ 
				    
					 while (m >= n) {
				            m -= n;
				        }
				        return m;
				 //   System.out.println(m+"%"+n+"="+m) ; 
				    
				}
				
				
	//question 3.5 Count Digits
				public static int countDigits(int n) {
						int count=0;

				         if(n<=0){
				         System.out.println("error input");}
				           while(n!=0 && n>0){
				                n = n/10;
				                count++;}
				         return count;     
				  //      System.out.printf("the number of digits is %d",count);
				       	}

				
	//question 3.6 Position
				public static int position(int n, int digit) {
					int position = 1;
			        while (n > 0) {
			            int lastDigit = n%10;
			            if (lastDigit == digit) {
			                return position;
			            }
			            n /= 10;
			            position++;
			        }
			        return -1;
			    }
			 
				

	//question 3.7 Extract Odd Digits
				public static long extractOddDigits(long n) {
					//
				
					long result = 0;
			        long multiplier = 1;
			        boolean oddDigitFound = false;

			        while (n > 0) {
			            long digit = n % 10;
			            if (digit % 2 != 0) {
			                result = result + digit * multiplier;
			                multiplier *= 10;
			                oddDigitFound = true;
			            }
			            n /= 10;
			        }

			        if (oddDigitFound) {
			            return result;
			        } else {
			            return -1; // No odd digits found
			        }
				
	    }
}
