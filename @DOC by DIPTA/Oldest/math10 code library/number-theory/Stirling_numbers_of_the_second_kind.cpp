void Stirling_numbers_of_the_second_kind(){
    FOR(i,1,1000){
        stirling_numbers[i][1] = 1;
        FOR(j,2,i){
            stirling_numbers[i][j] = (stirling_numbers[i-1][j-1] + (j*stirling_numbers[i-1][j]));
        }
    }
}
