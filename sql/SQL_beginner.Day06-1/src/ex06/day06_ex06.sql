select count(*)=1 as check1,
          max("start_value") = 1 as check2,
          max("last_value") > 5 as check3
      from pg_sequences
      where sequencename  = 'seq_person_discounts'