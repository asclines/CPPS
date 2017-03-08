import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Author: Alexander Clines
 * Problem URL: http://codeforces.com/contest/703/problem/A
 */


public class MishkaandGame {
    public static void main(String[] args) throws IOException {
        int n = 0;
        int totalM = 0;
        int totalC = 0;

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String nString = reader.readLine();
        n = Integer.parseInt(nString);


        for (int i = 0; i < n; i++){
            String nextLine = reader.readLine();
            String[] splitLine  = nextLine.split(" ");
            int m = Integer.parseInt(splitLine[0]);
            int c = Integer.parseInt(splitLine[1]);

            if ( m > c ){
                totalM ++;
             } else if (c > m ) {
                 totalC++;
            }
        }

        if (totalC > totalM) {
            System.out.println("Chris");
        } else if (totalM > totalC ) {
            System.out.println("Mishka");
        } else {
            System.out.println("Friendship is magic!^^");
        }
    }

}
