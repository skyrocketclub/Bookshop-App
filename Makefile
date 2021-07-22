.PHONY: clean All

All:
	@echo "----------Building project:[ Bookshop_Log - Debug ]----------"
	@cd "Bookshop_Log" && "$(MAKE)" -f  "Bookshop_Log.mk"
clean:
	@echo "----------Cleaning project:[ Bookshop_Log - Debug ]----------"
	@cd "Bookshop_Log" && "$(MAKE)" -f  "Bookshop_Log.mk" clean
