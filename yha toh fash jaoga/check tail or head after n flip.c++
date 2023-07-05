char getFinalState(int flips, bool isTail) {
    
    if (flips == 0) {
        return isTail ? 'T' : 'H';
    }

 
    if (isTail) {
        return getFinalState(flips - 1, false);
    }
    
    else {
        if (flips <= n ) {
            return getFinalState(flips - 1, true);
        } else {
            return getFinalState(flips - 1, false);
        }
    }
}

int main() {
    int numFlips = n;
    bool initialState = true;  // "tail"

     char finalState = getFinalState(numFlips, initialState);

    return finalState;
}