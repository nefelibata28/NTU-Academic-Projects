import java.util.Scanner;

public class Plane {
	Scanner sc = new Scanner(System.in);
	
	private PlaneSeat[] seat = new PlaneSeat[12];
    private int numEmptySeat = 12;
    
    public Plane() {
    	 for (int i = 0; i < seat.length; i++) {
             seat[i] = new PlaneSeat(i + 1);}
}
    
    private PlaneSeat[] sortSeats() {
    	PlaneSeat[] sortedSeats=seat.clone();
    	for (int i = 0; i < sortedSeats.length - 1; i++) {
            for (int j = i + 1; j < sortedSeats.length; j++) {
                if (sortedSeats[i].getcustomerId() > sortedSeats[j].getcustomerId()) {
                    PlaneSeat temp = sortedSeats[i];
                    sortedSeats[i] = sortedSeats[j];
                    sortedSeats[j] = temp;
                }
            }
        }
        return sortedSeats;
    }
    
    
    public void showNumEmptySeats() {
    	System.out.println("Number of empty seats: " + numEmptySeat);
    
    }
    
    public void showEmptySeats() {
    	 System.out.println("List of empty seats:");
         for (int i = 0; i < seat.length; i++) {
             if (!seat[i].isOccupied()) {
                 System.out.println("SeatID " + seat[i].getSeatId());
             }
         }
    	
    }
    public void AssignedSeats() {
    	PlaneSeat[] sortedSeats = bySeatId ? seat.clone() : sortSeats();
        System.out.println("List of assigned seats:");
        for (PlaneSeat seat : sortedSeats) {
            if (seat.isOccupied()) {
                System.out.println("SeatID " + seat.getSeatId() + " assigned to CustomerID " + seat.getCustomerID());
            }
        }
    	
    }
    public void assignSeat(int seatId, int cust_id){
    	
    	if (seatId >= 1 && seatId <= 12) {
            PlaneSeat seat = this.seat[seatId - 1];
            if (!seat.isOccupied()) {
                seat.assign(cust_id);
                numEmptySeat--;
                System.out.println("Seat assigned!");
            } else {
                System.out.println("Seat already assigned to a customer.");
            }
        }
    	}
    
    public void unAssignSeat(int seatId){
    	if (seatId >= 1 && seatId <= 12) {
            PlaneSeat seat = this.seat[seatId - 1];
            if (seat.isOccupied()) {
                seat.unAssign();
                numEmptySeat++;
                System.out.println("Seat unassigned!");
            } else {
                System.out.println("Seat is not assigned to any customer.");
            }
        }
    	
    }
    
   
        public void showAssignedSeats(boolean bySeatId) {
            PlaneSeat[] sortedSeats = bySeatId ? seat.clone() : sortSeats();
            System.out.println("List of assigned seats:");
            for (PlaneSeat seat : sortedSeats) {
                if (seat.isOccupied()) {
                    System.out.println("SeatID " + seat.getSeatId() + " assigned to CustomerID " + seat.getcustomerId());
                }
            }
        }

      
    }

    

