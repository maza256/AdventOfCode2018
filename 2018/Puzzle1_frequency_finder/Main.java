package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Timestamp;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        System.out.println("Puzzle 1\n");
        puzzle1();
        System.out.println("Puzzle 2\n");
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
        puzzle2();
        Timestamp timestampfinished = new Timestamp(System.currentTimeMillis());
        System.out.println(timestampfinished.getTime() - timestamp.getTime());

    }


    static public void puzzle1() {
    FileReader fr;
    int freq = 0;
    // write your code here
    try{
        fr = new FileReader("frequencies.txt");
        BufferedReader bufferedReader = new BufferedReader(fr);
        String s;

        while((s = bufferedReader.readLine()) != null )
        {
            freq += Integer.parseInt(s);
        }
    }
    catch(IOException e)
    {
        System.out.println(e);
    }

    System.out.println("Frequency is: " + freq);

    }

    static public void puzzle2() {
        FileReader fr;
        int freq = 0;
        String s;
        Set<Integer> hash_Set = new HashSet<Integer>();

        try{

           // BufferedReader bufferedReader = new BufferedReader(fr);
            while(true) {
                fr = new FileReader("frequencies.txt");
                BufferedReader bufferedReader = new BufferedReader(fr);
                while ((s = bufferedReader.readLine()) != null) {
                    freq += Integer.parseInt(s);
                    boolean result = hash_Set.add(freq);
                    if(!result)
                    {
                        System.out.println(freq);
                        return;
                    }
                }
                fr.close();
            }
        }
        catch(IOException e)
        {
            System.out.println(e);
        }

    }

}
