// Binary-Addition algorithm from ex. 2.1-4 of CLRS 3e
pub fn binary_addition(lhs: &[u8], rhs: &[u8]) -> Vec<u8> {
    let mut c = vec![0u8; lhs.len() + 1];
    let mut carry = 0u8;

    for ((i, a), b) in lhs.iter().enumerate().zip(rhs.iter()) {
        if *a == 1u8 && *b == 1u8 {
            if carry == 0u8 {
                c[i] = 0u8;
            } else {
                c[i] = 1u8;
            }
            carry = 1u8;
        } else if (*a == 1u8 && *b == 0u8) || (*a == 0u8 && *b == 1u8) {
            if carry == 0u8 {
                c[i] = 1u8;
            } else {
                c[i] = 0u8;
                carry = 1u8;
            }
        } else {
            c[i] = carry;
            carry = 0u8;
        }
    }

    c[lhs.len()] = carry;

    c
}
