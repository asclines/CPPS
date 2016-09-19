/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=14368&rd=16767
 * Challenge: SRM 695
 * Submitted and passed: YES
 * Tags:
 * Notes:
 */
public class BearNSWE {

    public double totalDistance(int[] a, String dir) {
        int UD = 0;
        int RL = 0;
        double result = 0.00;
        for(int i = 0; i < a.length; i++){
            result += a[i];
            char x = dir.charAt(i);
            switch (x){
                case 'N':
                    UD += a[i];
                    break;
                case 'S':
                    UD -= a[i];
                    break;
                case 'E':
                    RL -= a[i];
                    break;
                case 'W':
                    RL += a[i];
                    break;
            }


        }

        result += Math.sqrt(UD*UD + RL * RL);


        return result;
    }
}
