import java.util.ArrayList;


public class Main {

	public static void main(String[] args) {
		ArrayList<ArrayList> arLines = new ArrayList<ArrayList>();
		
		LoadFile lf = new LoadFile();
		
		arLines = lf.load("test.csv");
		
		for(int i = 0; i < arLines.size(); i++){
			System.out.println(arLines.get(i).get(0) + " | " + arLines.get(i).get(1) + " | " + arLines.get(i).get(2));
		}

	}

}
