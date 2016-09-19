package unfinished;
/**
 * Author: Alexander Clines
 * Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=1592&rd=4482
 * Challenge:  TCCC '03 Round 4
 * Submitted and passed: YES
 * Tags: Dynamic Programming, Graph Theory
 * Notes: the initMap() method feels wrong, otherwise, program is very space efficient
 */
import java.util.Arrays;

public class ChessMetric {
    long[][][] map; //[row][col][moves] = number of paths

    int size,numMoves;
    int[] start,end;

    public long howMany(int _size, int[] _start, int[] _end, int _numMoves) {
        this.size = _size;
        this.start = _start;
        this.end = _end;
        this.numMoves = _numMoves;
        initMap();
        return getPaths(start[0],start[1],numMoves);
    }

    private long getPaths(int row, int col, int moves){
        if((row<0)||(row>=size)){
            return 0L;
        }
        if((col<0)||(col>=size)){
            return 0L;
        }
        //This may not be needed
        if(moves <0 ){
            return 0L;
        }

        if(map[row][col][moves] == -1){
            map[row][col][moves] = 0;
            map[row][col][moves] += getPaths(row+2,col-1,moves-1);
            map[row][col][moves] += getPaths(row+2,col+1,moves-1);
            map[row][col][moves] += getPaths(row+1,col-2,moves-1);
            map[row][col][moves] += getPaths(row+1,col-1,moves-1);
            map[row][col][moves] += getPaths(row+1,col,moves-1);
            map[row][col][moves] += getPaths(row+1,col+1,moves-1);
            map[row][col][moves] += getPaths(row+1,col+2,moves-1);
            map[row][col][moves] += getPaths(row,col-1,moves-1);
            map[row][col][moves] += getPaths(row,col+1,moves-1);
            map[row][col][moves] += getPaths(row-1,col-2,moves-1);
            map[row][col][moves] += getPaths(row-1,col-1,moves-1);
            map[row][col][moves] += getPaths(row-1,col,moves-1);
            map[row][col][moves] += getPaths(row-1,col+1,moves-1);
            map[row][col][moves] += getPaths(row-1,col+2,moves-1);
            map[row][col][moves] += getPaths(row-2,col-1,moves-1);
            map[row][col][moves] += getPaths(row-2,col+1,moves-1);
        }

        return map[row][col][moves];
    }

    private void initMap(){
        map = new long[size][size][numMoves+1];
        for(long[][] matrix : map){
            for(long[] row: matrix){
                Arrays.fill(row,-1);
                row[0] = 0;
            }
        }
        map[end[0]][end[1]][0] = 1;
    }
}
