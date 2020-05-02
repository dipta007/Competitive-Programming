void Stirling_numbers_of_the_first_kind(){
    stirling_numbers[0][0]  =1;
    FOR(i,1,1000){
        FOR(j,1,i){
            stirling_numbers[i][j] = (stirling_numbers[i-1][j-1] + ((i-1)*stirling_numbers[i-1][j]));
        }
    }
}

