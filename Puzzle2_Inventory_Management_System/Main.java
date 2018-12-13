package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) {
	    part1();
        part2();
    }

    static public void part1()
    {
        FileReader fr;
        int dubs = 0;
        int treb = 0;
        // write your code here
        try{
            fr = new FileReader("inventory_list.txt");
            BufferedReader bufferedReader = new BufferedReader(fr);
            String temp;
            char[] s;
            while((temp = bufferedReader.readLine()) != null )
            {
                s = temp.toCharArray();
                boolean incrementeddubs = false, incrementedtrebs = false;
                int count = 1;
                for(int i = 0; i < 26; i++) {
                    char c = s[i];
                    if(c != '+')
                    {
                        for(int k = i + 1; k < 26; k++)
                        {
                            if(c == s[k]) {
                                count++;
                                s[k] = '+';
                            }
                        }
                        if(count == 2 && !incrementeddubs) {
                            dubs++;
                            incrementeddubs = true;
                        }
                        if(count == 3 && !incrementedtrebs) {
                            treb++;
                            incrementedtrebs = true;
                        }
                        count = 1;
                    }
                }
            }
            System.out.println("Number is: " + dubs + " "  + treb + " "+ dubs*treb);
        }
        catch(IOException e)
        {
            System.out.println(e);
        }

    }

    static public void part2() {
        FileReader fr;
        int dubs = 0;
        int treb = 0;
        // write your code here
        try {
            fr = new FileReader("inventory_list.txt");
            BufferedReader bufferedReader = new BufferedReader(fr);
            List<String> words = new ArrayList<>();
            String s, t;
            int match = 0;

            while ((s = bufferedReader.readLine()) != null) {
                words.add(s);
            }
            int testing = 0;
            int position = 0;
            int mistakes = 2;
            while(match == 0)
            {
                for(int i = 1; i < words.size(); i++)
                {
                    t = words.get(i);
                    if(testing == 0)
                    {
                        s = words.get(position);
                        position++;
                        testing = 1;
                    }
                    mistakes = 2;
                    for(int p = 0; p < 26; p++)
                    {
                        if(!(s.charAt(p) == t.charAt(p)))
                        {
                            mistakes--;
                        }
                        if(mistakes == 0)
                            continue;
                    }
                    if(mistakes == 1)
                    {
                        System.out.println(s + "\n" + t + "\n");
                        match++;
                        break;
                    }

                }
                testing = 0;

            }


        }
        catch(IOException e)
        {
            System.out.println(e);
        }
    }

}
