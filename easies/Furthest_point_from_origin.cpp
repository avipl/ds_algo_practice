class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCnt = 0, rCnt = 0, blankCnt = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') lCnt++;
            else if(moves[i] == 'R') rCnt++;
            else blankCnt++;
        }
        
        if(lCnt >= rCnt) return (lCnt - rCnt) + blankCnt;
        
        return (rCnt - lCnt) + blankCnt;
    }
};