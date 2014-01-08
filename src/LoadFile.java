import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class LoadFile {
	// TODO enum fuer vor, nach, gleich ....
	public enum Relation {
		 VOR, NACH, GLEICH, START, STARTI, FINISH, FINISHI, DURING, DURINGI, OVERLAY, OVERLAYI, MEETS, MEETSI;
	}
	
	public ArrayList<ArrayList> load(String file){
		
		ArrayList<ArrayList> arLines = new ArrayList<ArrayList>();
		FileReader fr = null;
		BufferedReader br = null;
		try{
			fr = new FileReader(file);
		
		    br = new BufferedReader(fr);
		}catch(Exception e){
			System.out.println("EXCEPTIOOOOOOOONNNNN!!!! YEAH!!!! HURRAAAAAAA!!!");
		}
		    String zeile = "";
		    // skip the first line
		    try{
		    	
		   
		    br.readLine();
		    while((zeile = br.readLine()) != null){
		    	ArrayList<Integer> arAttributes = new ArrayList<Integer>();
		    	String [] arZeile = zeile.split(";");
		    	switch(arZeile[2]){
			    	case "vor": arAttributes.add(Relation.VOR.ordinal());
			    	break;
			    	case "nach": arAttributes.add(Relation.NACH.ordinal());
			    	break;
			    	case "gleich": arAttributes.add(Relation.GLEICH.ordinal());
			    	break;
			    	case "start": arAttributes.add(Relation.START.ordinal());
			    	break;
			    	case "starti": arAttributes.add(Relation.STARTI.ordinal());
			    	break;
			    	case "endet": arAttributes.add(Relation.FINISH.ordinal());
			    	break;
			    	case "endeti": arAttributes.add(Relation.FINISHI.ordinal());
			    	break;
			    	case "waehrend": arAttributes.add(Relation.DURING.ordinal());
			    	break;
			    	case "waehrendi": arAttributes.add(Relation.DURINGI.ordinal());
			    	break;
			    	case "uerblagert": arAttributes.add(Relation.OVERLAY.ordinal());
			    	break;
			    	case "ueberlagerti": arAttributes.add(Relation.OVERLAYI.ordinal());
			    	break;
			    	case "angrenzend": arAttributes.add(Relation.MEETS.ordinal());
			    	break;
			    	case "angrenzendi": arAttributes.add(Relation.MEETSI.ordinal());
			    	break;
			    	default: System.out.println("Fail Hardcorly");
		    	}
		    	arAttributes.add(Integer.parseInt(arZeile[0]));
		    	arAttributes.add(Integer.parseInt(arZeile[1]));
		    	arLines.add(arAttributes);
		    }

		    br.close();
		    }catch(Exception es){
		    	System.out.println("Another Exception");
		    }
		
		return arLines;
	}
}
