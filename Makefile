all:
	$(MAKE) --directory Versuch0 all
	$(MAKE) --directory Versuch1_1 all
	$(MAKE) --directory Versuch1_2 all
	$(MAKE) --directory Versuch2_1 all
	$(MAKE) --directory Versuch2_2 all
	$(MAKE) --directory Versuch2_3 all
	$(MAKE) --directory Versuch3 all
	$(MAKE) --directory Versuch4 all
	
clean:
	$(MAKE) --directory Versuch0 clean