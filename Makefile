SUBDIRS = icecast-2.2.0 icecast-2.3.0.rc1 icecast-2.3.0.rc2 icecast-2.3.0.rc3 icecast-2.3.1

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@/src

clean:
	-for d in $(SUBDIRS); do (cd $$d/src; $(MAKE) clean ); done
