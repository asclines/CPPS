/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=2402
 * Submitted and passed: YES
 * Tags: Dynamic Programming
 * Notes: This solution does not feel like it is the best way. The way this problem works is it picks two starting places, the first and the second house.
 * For each starting place, the method fetchGP uses the starting place as a pivot point to calculate greatest payment.
 *
 */
public class BadNeighbors {
    int[] gp;
    int[] values;
    public 	int maxDonations(int[] donations){

        if(donations.length == 1){
            return donations[0];
        } else if(donations.length == 2){
            if(donations[0] > donations[1])
                return donations[0];
            else
                return donations[1];
        } else{
            int[] subtrees = new int[2];

            values = donations;
            values[donations.length-1] = 0;
            for(int i = 0; i < 2 ; i++) {

                gp = new int[donations.length];
                gp[donations.length - 1] = donations[donations.length - 1];
                gp[donations.length - 2] = donations[donations.length - 2];
                subtrees[i] = fetchGP(i);
                values = donations;
            }
            return Math.max(subtrees[0],subtrees[1]);
        }
    }

    private int fetchGP(int index){
        if(index >= gp.length)
            return 0;

        if(gp[index]==0){
            gp[index] = values[index] + Math.max(fetchGP(index+2),fetchGP(index+3));
        }

        return gp[index];
    }

}
