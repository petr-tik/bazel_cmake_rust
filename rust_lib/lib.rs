#[no_mangle]
pub extern "C" fn my_favorite_number() -> i32 {
    4
}

#[no_mangle]
pub extern "C" fn complex_maths(inp: i32) -> i32 {
    let factor = 10i32;
    // TODO aargh unsafe
    return inp.checked_mul(factor).unwrap();
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_my_favorite_number() {
        assert_eq!(4, my_favorite_number());
    }

    #[test]
    fn test_my_complex_maths() {
        assert_eq!(50, complex_maths(5));
    }
}
