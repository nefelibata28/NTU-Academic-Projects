import java.util.Scanner;

public class PlaneSeat {

	//public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		private int seatId;
		private boolean assigned;
		private int customerId;
		
		public PlaneSeat(int seat_id) {
			this.seatId=seat_id;
			this.assigned=false ; //initially unassigned
			this.customerId=0; //no customer initially
		
		}
		
		
		public int getSeatId() {

			return seatId;
		}
	
	
	public int getcustomerId() {
		return customerId;
	}

	public boolean isOccupied() {
	    return assigned;
	}

	public void assign( int cust_id) {
		if(!assigned) {
			this.customerId=cust_id;
			this.assigned=true;
			System.out.println("Seat"+seatId+"assigned to customer"+customerId);
	}else {
		System.out.println("Seat"+seatId+"assigned already to customer"+customerId);
	}
	
	}
 
	public void unAssign() {
		if(assigned) {
			this.customerId=0;
			this.assigned=false;
			System.out.println("Seat"+seatId+"unassigned from customer " +customerId);
	}else {
		System.out.println("Seat"+seatId+"is not assigned to any customer ");
	}
	
	}
		
	
	}

