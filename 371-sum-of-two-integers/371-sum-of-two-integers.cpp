class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
    bool hasCarry = false;

    for (int i = 0; i < 32; i++) {

        bool isSeta = false;
        bool isSetb = false;

        if ((a >> i) == 0 && (b >> i) == 0){
             if (hasCarry) {

                ans = ans | (1 << i);
            }
            break;
        }

        if ((a >> i) & 1)
            isSeta = true;
        if ((b >> i) & 1)
            isSetb = true;

        if (hasCarry) {
            // deb(i)
            if (isSeta && isSetb) {
                ans = ans | (1 << i);
                hasCarry = true;
            }
            else if (isSeta == false && isSetb == false) {
                ans = ans | (1 << i);
                hasCarry = false;
            }
            else if (isSeta == false && isSetb) {
                // deb("ee")
                hasCarry = true;

            }
            else if (isSeta && isSetb == false) {
                hasCarry = true;

            }

        } else {
            // deb(i)

            if (isSeta && isSetb) {
                hasCarry = true;

            }
            else if (isSeta == false && isSetb == false) {
                hasCarry = false;

            }
            else if (isSeta == false && isSetb) {

                ans = ans | (1 << i);
                hasCarry = false;

            }
            else if (isSeta && isSetb == false) {
                ans = ans | (1 << i);
                hasCarry = false;
            }

        }

    }
    return ans;
    }
};