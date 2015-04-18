assert 'Crand#rand' do
  assert_kind_of Integer, Crand.rand
end

assert 'Crand#srand' do
  assert_equal Crand, Crand.srand(303)
end
