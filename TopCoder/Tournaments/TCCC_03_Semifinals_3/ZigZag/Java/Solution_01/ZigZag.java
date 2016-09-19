/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=1259
 * Submitted and passed: YES
 * Tags: Dynamic Programming
 * Notes:
 */
public class ZigZag {

    public int longestZigZag(int[] sequence){
        char[] differences = new char[sequence.length];
        differences[0] = '=';
        int count = 1;

        for(int i = 1; i < sequence.length; i++){
            if(sequence[i] > sequence[i-1]){
                differences[i] = '+';
            } else if(sequence[i] < sequence[i-1]){
                differences[i] = '-';
            } else{
                differences[i] = differences[i-1];
            }

            if(differences[i] != differences[i-1]){
                count++;
            }
        }
        return count;
    }
}
