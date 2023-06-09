
NO_OF_CHARS = 256
 
def badCharHeuristic(string, size):
    """
    The preprocessing function for
    Boyer Moore"s bad character heuristic
    """
 
    # Initialize all occurrence as -1
    badChar = [-1]*NO_OF_CHARS
 
    # Fill the actual value of last occurrence
    for i in range(size):
        badChar[ord(string[i])] = i;
 
    # retun initialized list
    return badChar
 
def search(txt, pat):
    """
    A pattern searching function that uses Bad Character
    Heuristic of Boyer Moore Algorithm
    """
    m = len(pat)
    n = len(txt)
 
    # create the bad character list by calling
    # the preprocessing function badCharHeuristic()
    # for given pattern
    badChar = badCharHeuristic(pat, m)
 
    # s is shift of the pattern with respect to text
    s = 0
    while(s <= n-m):
        j = m-1
 
        # Keep reducing index j of pattern while
        # characters of pattern and text are matching
        # at this shift s
        while j>=0 and pat[j] == txt[s+j]:
            j -= 1
 
        # If the pattern is present at current shift,
        # then index j will become -1 after the above loop
        if j<0:
            print(f'Pattern occur at shift = {s}')
        	s += (m-badChar[ord(txt[s+m])] if s+m<n else 1)
        

print(search('helololo', 'lo'))