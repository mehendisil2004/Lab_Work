class Room {
    private double height;
    private double width;
    private double breadth;

    public Room(double height, double width, double breadth) {
        this.height = height;
        this.width = width;
        this.breadth = breadth;
    }

    public double volume() {
        return height * width * breadth;
    }
}

public class RoomDemo {
    public static void main(String[] args) {
        Room room1 = new Room(10, 15, 20);
        Room room2 = new Room(12, 18, 25);

        System.out.println("Volume of Room 1: " + room1.volume() + " cubic units");
        System.out.println("Volume of Room 2: " + room2.volume() + " cubic units");
    }
}
