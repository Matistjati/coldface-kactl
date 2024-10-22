/**
 * Author: unknown
 * Description: Iterates through all submasks of a bitmask.
 * Doing this for every mask < $2^N$ amortizes to $O(3^N)$
*/

for (int s=mask; s; s=(s-1)&mask)