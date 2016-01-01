/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=1889&rd=4709
 * Challenge: TCO '03 Semifinals 4
 * Submitted and passed: YES
 * Tags: Dynamic Programming
 * Notes:
 */
 import java.util.HashMap;
 
public class AvoidRoads {

    HashMap<String,Long> paths;
    HashMap<String,Boolean> badPaths;
    int w,h;
    public long numWays(int width, int height, String[] bad){
        paths = new HashMap<>();
        badPaths = new HashMap<>();

        for(String bp:bad){
            String[] data = bp.split(" ");
            String key = data[0] + " " + data[1] + " " + data[2] + " " + data[3];
            badPaths.put(key,true);
            key = data[2] + " " + data[3] + " " + data[0] + " " + data[1];
            badPaths.put(key,true);

        }

        w = width;
        h = height;

        return getPaths(0,0);
    }

    private long getPaths(int x, int y){
        if((x==w)&&(y==h))
            return 1L;
        if((x>w)||(y>h))
            return 0L;

        String key = x+" "+y;
        if(paths.get(key) == null){
            long sum = 0;

            String newKey = key + " " +x+" " + (y+1);
            if(badPaths.get(newKey) == null) {
                sum += getPaths(x,y+1);
            }


            newKey = key + " " +(x+1)+" " + y;
            if(badPaths.get(newKey ) == null) {
                sum += getPaths(x+1,y);
            }



            paths.put(key,sum);

        }


        return paths.get(key);
    }


}
