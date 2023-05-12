void Tests::run_tests()
{
	test_add();
	test_finished();
	cout << "Tested\n";
}

void Tests::test_add()
{
	Repo repo;

	repo.add_repo(Project("a", "b", "2020", 10000, true));
	repo.add_repo(Project("c", "d", "2021", 30000, false));
	repo.add_repo(Project("a", "b", "2020", 10000, true));

	assert(repo.get_projects().size() == 2);
	assert(repo.get_projects()[0].get_name() == "a");

	Service service;
	service.add(Project("a", "b", "2020", 10000, true));
	service.add(Project("c", "d", "2021", 30000, false));
	service.add(Project("a", "b", "2020", 10000, true));

	assert(service.get_projects().size() == 2);
	assert(service.get_projects()[0].get_name() == "a");
	cout << "add tested\n";
}

void Tests::test_finished()
{
	Service service;

	service.add(Project("a", "b", "2020", 10000, true));
	service.add(Project("b", "a", "2021", 30000, false));

	assert(service.total_finished_test() == 1);

	cout << "finished projects function tested\n";
}
