#!/bin/sh

function(){
    touch $1__.cc
    cat ../template.cc >> $1__.cc
    if [ $?==0 ]
    then
        echo "successfull"
    fi
}


fun(){
    for file in $*
    do
        function $file
    done
}


# fun 060_PermutationSequence 077_Combinations
# fun 079_WordSearch 089_GrayCode 090_SubsetsII
# fun 093_RestoreIPAddresses 126_WordLadderII
# fun 131_PalindromePartitioning 140_WordBreakII 211_AddAndSearchWord 212_WordSearchII 216_CombinationSumIII
# fun 357_CountNumbersWithUniqueDigits