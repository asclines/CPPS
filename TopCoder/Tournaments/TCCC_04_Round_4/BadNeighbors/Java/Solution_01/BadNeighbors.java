/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=2402
 * Challenge: TCCC '04 Round 4
 * Submitted and passed: YES
 * Tags: Dynamic Programming
 * Notes: This solution does not feel like it is the best way. The way this problem works is it picks three starting places, the first, second and third houses.
 * For each starting place, the method fetchGP uses the starting place as a pivot point to calculate greatest payment.
 *
 */
public class BadNeighbors {
    public 	int maxDonations(int[] donations){

        if(donations.length == 1){
            return donations[0];
        } else if(donations.length == 2){
            if(donations[0] > donations[1])
                return donations[0];
            else
                return donations[1];
        } else{

            int[] subtrees = new int[3];

            int[] gp = new int[donations.length];
            subtrees[2] = fetchGPReverse(donations.length-1,donations,gp);

            gp = new int[donations.length];
            subtrees[1] = fetchGP(1,donations,gp);;

            gp = new int[donations.length];
            gp[donations.length - 1] = -1;
            subtrees[0] = fetchGP(0,donations,gp);

            return Math.max(subtrees[0],Math.max(subtrees[1],subtrees[2]));
        }
    }

    private int fetchGPReverse(int index, int[] dontations, int[] gp){
        if(index <= 1){
            return 0;
        }

        if(gp[index] == 0){
            gp[index] = dontations[index] + Math.max(fetchGPReverse(index-2,dontations,gp),fetchGPReverse(index-3,dontations,gp));
        }

        return gp[index];
    }
    private int fetchGP(int index, int[] donations, int[] gp){
        if(index >= gp.length)
            return 0;

        if(gp[index] == -1)
            return 0;

        if(gp[index]==0){
            gp[index] = donations[index] + Math.max(fetchGP(index+2,donations,gp),fetchGP(index+3,donations,gp));
        }

        return gp[index];
    }

}