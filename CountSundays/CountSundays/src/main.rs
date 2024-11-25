
// In this program the idea is calculating the number of 
use std::vec;

fn main() {
    let x  = count_sundays();
    println!("The number of sundays that fall on the 1st day of the month over a centuary is {}",x);
}

fn count_sundays()-> i32{

    /*
    global variable to hold the number of sundays tha fall on the 1st day of the month(date 1)
    loop from 1 to 100 (centuary)
    */
    let mut sundays_count = 0;

    /*The idea is youre given starting date of jan 1st 1900 to be a monday.
    1900 being not a leap year 365 days to 1st jan 1901 which was a tuesday */
    let mut current_day = 1 + 365;          

    let mut month_in_days = vec![31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    for year in 1901..=2000{
        if (year % 4 == 0 && year % 100 != 0) || (year % 4 ==0){
            month_in_days[1] = 29;
        }
        for month in 1..=12{
            // variable for holding the accumulation
            let accumulation = current_day + month_in_days[month-1];
            if accumulation % 7 ==0 {
                sundays_count += 1;
            }
            
            current_day = accumulation;
        }
        month_in_days[1] = 28;
    }
    
    return sundays_count;    
}
