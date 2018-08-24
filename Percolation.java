//THIS PROGRAM WAS CREATED BY DEVIN BROWN 
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdRandom; 
import edu.princeton.cs.algs4.StdStats; 


public class Percolation {
  
    private int n;
    private int virtualTop;
    private int virtualBottom;
    private boolean[][] sites; // N-by-N grid
    private WeightedQuickUnionUF weightedQuickUnionUF1; // Used for determining whether the system is percolate
    private WeightedQuickUnionUF weightedQuickUnionUF2; // Used for opening sites
  
    // create N-by-N grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("N must be greater than 0.");
        }
        this.n = n;
        sites = new boolean[n][n];
        weightedQuickUnionUF1 = new WeightedQuickUnionUF(n * n + 2); // Has both virtualTop and virtualBottom
        weightedQuickUnionUF2 = new WeightedQuickUnionUF(n * n + 1); // Has only virtualTop
      
        virtualTop = n * n;
        virtualBottom = n * n + 1;
    }
  
    // convert coordinate to index
    private int xyToIndex(int row, int col) {
        return (row - 1) * n + col - 1;
    }
  
    // throw an exception for invalid indices
    private void validateIndex(int row, int col) {
        // col and row are range of 1 ~ N
        if (row < 1 || row > n)
            throw new IndexOutOfBoundsException("Row must be range of 1 ~ N.");
        if (col < 1 || col > n)
            throw new IndexOutOfBoundsException("Col must be range of 1 ~ N.");
    }
  
    // open the site (row, col) if it is not open already
    public void open(int row, int col) {
      
        validateIndex(row, col);
      
        if (!isOpen(row, col)) {
          
            int idx = xyToIndex(row, col);
            sites[row - 1][col - 1] = true;
          
            if (row == 1) {
                weightedQuickUnionUF1.union(idx, virtualTop);
                weightedQuickUnionUF2.union(idx, virtualTop);
            }
          
            if (row == n)
                weightedQuickUnionUF1.union(idx, virtualBottom);
          
            if (row > 1 && isOpen(row - 1, col)) {
                weightedQuickUnionUF1.union(idx, xyToIndex(row - 1, col));
                weightedQuickUnionUF2.union(idx, xyToIndex(row - 1, col));
            }
          
            if (row < n && isOpen(row + 1, col)) {
                weightedQuickUnionUF1.union(idx, xyToIndex(row + 1, col));
                weightedQuickUnionUF2.union(idx, xyToIndex(row + 1, col));
            }
          
            if (col > 1 && isOpen(row, col - 1)) {
                weightedQuickUnionUF1.union(idx, xyToIndex(row, col - 1));
                weightedQuickUnionUF2.union(idx, xyToIndex(row, col - 1));
            }
          
            if (col < n && isOpen(row, col + 1)) {
                weightedQuickUnionUF1.union(idx, xyToIndex(row, col + 1));
                weightedQuickUnionUF2.union(idx, xyToIndex(row, col + 1));
            }
        }
    }
  
    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        validateIndex(row, col);
        return sites[row - 1][col - 1];
    }
  
    // is the site (row, col) full? (Use weightedQuickUnionUF2 to determine if the site is full)
    public boolean isFull(int row, int col) {
        boolean isfull = false;
        validateIndex(row, col);
        if (isOpen(row, col)) {
            isfull = weightedQuickUnionUF2.connected(xyToIndex(row, col), virtualTop);
        }
        return isfull;
    }
  
    // does the system percolate? (Use weightedQuickUnionUF1 to determine if the system is percolate)
    public boolean percolates() {
        return weightedQuickUnionUF1.connected(virtualBottom, virtualTop);
    }
  
    // test client (optional)
    public static void main(String[] args) {
      
        System.out.println("Please input N: ");
        int n = StdIn.readInt();
      
        Percolation percolation = new Percolation(n);
        while (!percolation.percolates()) {
            int row = StdRandom.uniform(n) + 1; // row is range of 1 ~ N
            int col = StdRandom.uniform(n) + 1; // col is range of 1 ~ N
            percolation.open(row, col);
        }
        int numberOfOpenSites = 0;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                if (percolation.isOpen(r, c)) {
                    numberOfOpenSites++;
                    }
                }
            }
        double prob = (double) (numberOfOpenSites) / (double) (n * n);
        System.out.println(prob);
      
        System.out.println(percolation.isFull(n, n));
    }
}

