class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        int mask = (1 << (r-l+1));
        mask--;
        mask = (mask << (l-1));
        mask = (mask & y);
        x = x | mask;
        return x;
    }
};

// Calculating the mask: The code calculates the mask using the formula mask = (1 << (r-l+1));, which involves shifting bits and arithmetic operations. This step has a time complexity of O(1) since it only depends on the difference between r and l and does not scale with the input size.

// Reducing the mask by 1: The operation mask-- is a simple decrement operation and has a time complexity of O(1) as it does not depend on the input size.

// Shifting the mask: The code performs a left shift operation to align the mask with the desired range. The shift operation has a time complexity of O(1) as it only depends on the constant value l and not on the input size.

// Applying the mask: The code applies the mask to the bits in y using the bitwise AND operation mask = (mask & y);. This operation takes constant time and does not depend on the input size.

// Updating x using the masked bits: The code performs a bitwise OR operation x = x | mask; to set the corresponding bits in x using the masked bits from y. This operation has a time complexity of O(1) as it does not depend on the input size.

// Overall, the time complexity of the provided code is O(1) because the number of operations remains constant and does not scale with the input size.