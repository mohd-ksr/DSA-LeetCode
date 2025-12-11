

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, List<Integer>> rows = new HashMap<>();
        Map<Integer, List<Integer>> cols = new HashMap<>();
        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];
            rows.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
            cols.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
        }

        for (List<Integer> list : rows.values()) {
            Collections.sort(list);
        }
        for (List<Integer> list : cols.values()) {
            Collections.sort(list);
        }

        int count = 0;

        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];

            List<Integer> rowList = rows.get(y);
            List<Integer> colList = cols.get(x);

            int rowPos = Collections.binarySearch(rowList, x);
            int colPos = Collections.binarySearch(colList, y);

            boolean hasLeft = (rowPos > 0);
            boolean hasRight = (rowPos < rowList.size() - 1); 
            boolean hasUp = (colPos > 0);  
            boolean hasDown = (colPos < colList.size() - 1); 

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
}
