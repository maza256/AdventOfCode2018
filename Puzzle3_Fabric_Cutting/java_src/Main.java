import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.Format;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {

    static Map<String, Fabric> fabricList;

    public static void main(String[] args) {
        fabricList = new HashMap();
        part1();
        part2();
    }



    static public void part1() {
        FileReader fr;

        // write your code here
        try{
            fr = new FileReader("full_cuts.txt");
            BufferedReader bufferedReader = new BufferedReader(fr);
            String temp;
            char[] s;
            while((temp = bufferedReader.readLine()) != null ) {

                Pattern P = Pattern.compile("#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+).*");
                Matcher m = P.matcher(temp);
                m.find();

                Fabric fabricTemp = new Fabric( Integer.parseInt(m.group(1)),
                                                Integer.parseInt(m.group(2)),
                                                Integer.parseInt(m.group(4)),
                                                Integer.parseInt(m.group(3)),
                                                Integer.parseInt(m.group(5))
                                                );
                fabricList.put(m.group(1), fabricTemp);

            }

        int[][] window = new int[1000][1000];
        int overlap = 0;
        Fabric tempFab;
        for(int i = 1; i < fabricList.size() + 1; i++)
        {
            tempFab = fabricList.get(Integer.toString(i));


            for(int k = tempFab.getLeft(); k < tempFab.getLeft() + tempFab.getWidth(); k++)
            {
                for(int l = tempFab.getTop(); l < tempFab.getHeight() + tempFab.getTop(); l++)
                {

                    if(window[k][l] == 0)
                    {
                        window[k][l] = tempFab.getId();
                    }
                    else
                    {
                        if(window[k][l] != -1)
                        {
                            overlap++;
                        //    tempFab.set_overlap(1);
                            fabricList.get(Integer.toString(i)).set_overlap(1);
                            fabricList.get(Integer.toString(window[k][l])).set_overlap(1);
                            window[k][l] = -1;
                        }
                        window[k][l] = -1;
                        tempFab.set_overlap(1);
                    }
                }
            }

        }

        System.out.printf("Overlap is: %d\n", overlap);

        for(int i = 1; i < fabricList.size() + 1; i++)
        {
            if(fabricList.get(Integer.toString(i)).getOverlap() == 0)
                System.out.printf("Non-Overlapped is: %d\n", fabricList.get(Integer.toString(i)).getId());
        }

        }
        catch(IOException e)
        {
            System.out.println(e);
        }



//        fabricList = new List<Fabric>();
//        fabricTemp = new Fabric()
     }

    static public void part2() {
    }


}
