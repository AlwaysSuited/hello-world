//THIS PROGRAM WAS CREATED BY DEVIN BROWN AND DANIEL NIX
import java.lang.*;
import java.util.*;
import edu.princeton.cs.algs4.*;

public final class Term implements Comparable<Term> {
 private final String query;
 private final double weight;
 
// Initializes a term with the given query string and weight.
 public Term(String query, double weight) {
  if (query == null) throw new NullPointerException("Query cannot be null");
  if (weight < 0) throw new IllegalArgumentException("weight must not be less than 0");
  this.query = query;
  this.weight = weight;
 }
 
// Compares the two terms in descending order by weight.
 public static Comparator<Term> byReverseOrder() {
  return new ComparatorByReverseOrderWeight();
 }
 
// Compares the two terms in lexicographic order but using only the first r characters of each query.
 public static Comparator<Term> byPrefixOrder(int r) {
  if (r < 0) throw new IllegalArgumentException("r must not be less than 0");
  return new ComparatorByPrefixOrderQuery(r);
 }
 
// Compares the two terms in lexicographic order by query.
 @Override
 public int compareTo(Term o) {
  return this.query.compareTo(o.query);
 }
 
 // Returns a string representation of this term in the following format:
    // the weight, followed by a tab, followed by the query.
 @Override
 public String toString() {
  return weight + "\t" + query;
 }
 
 private static class ComparatorByReverseOrderWeight implements Comparator<Term> {
  @Override
  public int compare(Term a, Term b) {
   if (a.weight == b.weight) return 0;
   if (a.weight > b.weight) return -1;
   return 1;
  }
 }
 
 private static class ComparatorByPrefixOrderQuery implements Comparator<Term> {
  private int r;
  
  private ComparatorByPrefixOrderQuery(int r) {
   this.r = r;
  }

  @Override 
  public int compare(Term a, Term b) {
   String prefixA;
   String prefixB;
   
   if (a.query.length() < r) prefixA = a.query;
   else prefixA = a.query.substring(0, r);
   
   if (b.query.length() < r) prefixB = b.query;
   else prefixB = b.query.substring(0, r);

   return prefixA.compareTo(prefixB);
  }
 }
 //unit testing
 public static void main(String[] args) {
  return;
 }
}