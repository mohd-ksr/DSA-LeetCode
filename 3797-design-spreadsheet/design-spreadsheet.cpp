class Spreadsheet {
private:
    vector<vector<int>>sheet;
    int extractVal(string cell){
        if(!cell.size())return 0;
        if(isdigit(cell[0]))return stoi(cell);
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1)) - 1;
        return sheet[row][col];
    }
public:
    Spreadsheet(int rows) {
        for(int i=0; i<rows; i++){
            vector<int>temp;
            for(int j=0; j<26; j++){
                temp.push_back(0);
            }
            sheet.push_back(temp);
        }
    }
    
    void setCell(string cell, int value) {
        char ch = cell[0];
        int col = (ch-'A');
        string s = cell.substr(1);
        int row = stoi(s) - 1;
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        char ch = cell[0];
        int col = (ch-'A');
        string s = cell.substr(1);
        int row = stoi(s) - 1;
        sheet[row][col]=0;
    }
    
    int getValue(string formula) {
        if(!formula.size())return 0;
        if(formula[0]=='=')formula=formula.substr(1);
        size_t pos = formula.find('+');
        string left = formula.substr(0,pos);
        string right = formula.substr(pos+1);
        int v1 = extractVal(left);
        int v2 = extractVal(right);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */