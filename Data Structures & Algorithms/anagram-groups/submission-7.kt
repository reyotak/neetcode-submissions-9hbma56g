/* Create a map with sorted strings -> strs index
 * For each string, sort it for a-z
 * Check if it's in the map
 * If not, add to the map with the strs index
 * Print the map using the rule: for each key print the strs[index]
*/

class Solution {
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        return strs
            .groupBy{s -> s.toCharArray().sorted().joinToString("")}
            .values
            .toList()
    }
}
