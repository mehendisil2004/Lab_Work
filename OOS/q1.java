class Room {
    int height, width, breadth;

    Room(int height, int width, int breadth) {
        this.height = height;
        this.width= width;
        this.breadth= breadth;
    }

    int vol() {
        return height * width * breadth;
    }
}

class RoomDemo {
    public static void main(String[] args) {
        Room r= new Room(7, 10, 12);

        System.out.println("Vol of room: " +r.vol());
    }
}
