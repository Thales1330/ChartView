.PHONY: clean All

All:
	@echo "----------Building project:[ ChartView - Debug ]----------"
	@cd "ChartView" && "$(MAKE)" -f  "ChartView.mk"
clean:
	@echo "----------Cleaning project:[ ChartView - Debug ]----------"
	@cd "ChartView" && "$(MAKE)" -f  "ChartView.mk" clean
