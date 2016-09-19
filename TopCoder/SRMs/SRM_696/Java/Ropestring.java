package srm696;

import java.util.ArrayList;
import java.util.Collections;


/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=14373&rd=16775
 * Challenge: SRM 696
 * Submitted and passed: YES
 * Tags: Dynamic Programming
 * Notes:
 */
public class Ropestring {

    public String makerope(String s) {
        ArrayList<Integer> evenRopes = new ArrayList<>();
        ArrayList<Integer> oddRopes = new ArrayList<>();
        int dotCount = 0;

        int n = s.length();
        for(int i = 0; i < n; i++){
            char x = s.charAt(i);
            int ropeSize = 0;
            while ( x == '-'){
                ropeSize++;
                i++;
                if ( i < n)
                    x = s.charAt(i);
                else
                    break;
            }
            if (i < n)
                dotCount++;
            if ( ropeSize > 0 ){
                if ( ropeSize% 2 == 0){
                 evenRopes.add(ropeSize);
                } else {
                 oddRopes.add(ropeSize);
                }
            }

        }

        Collections.sort(evenRopes,Collections.<Integer>reverseOrder());
        Collections.sort(oddRopes,Collections.<Integer>reverseOrder());

        StringBuilder result = new StringBuilder();
        for ( Integer rope: evenRopes){
            for( int i = 0; i < rope; i++){
                result.append('-');
            }
            if (dotCount > 0){
                result.append('.');
                dotCount--;
            }
        }

        for ( Integer rope: oddRopes){
            for( int i = 0; i < rope; i++){
                result.append('-');
            }

            if ( dotCount > 0){
                result.append('.');
                dotCount--;
            }
        }


        for ( int i = 0; i < dotCount; i++){
            result.append('.');
        }

        return result.toString();
    }
}
