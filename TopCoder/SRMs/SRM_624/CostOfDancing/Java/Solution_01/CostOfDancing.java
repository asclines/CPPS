import static java.util.Arrays.sort;

/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=13195
 * Challenge: SRM 624
 * Submitted and passed: YES
 * Tags: Graph Theory, Greedy, Sorting
 * Notes:
 */
public class CostOfDancing {

    public int minimum(int K, int[] danceCost){
        int minCost =0;
        sort(danceCost);
        for(int i =0;i<K;i++){
            minCost += danceCost[i];
        }
        return minCost;
    }
}
