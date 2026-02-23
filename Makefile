# Makefile - Airline Check-in System
# Compilation: make
# Cleanup: make clean
# Rebuild: make rebuild
# Tests: make test

CC = gcc
CFLAGS = -Wall -Iinclude -std=c99
SRCDIR = src
BINDIR = bin
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj
TESTDIR = tests/unit

# Sources
COMPANY_SRC = $(wildcard $(SRCDIR)/company/*.c)
CLIENT_SRC = $(wildcard $(SRCDIR)/client/*.c)

COMPANY_OBJ = $(COMPANY_SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Targets
.PHONY: all clean rebuild test help

all: $(BINDIR)/company $(BINDIR)/client
	@echo "✅ Compilation completed successfully!"
	@echo "   Server: $(BINDIR)/company"
	@echo "   Client:  $(BINDIR)/client"

$(BINDIR)/company: $(COMPANY_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "✅ Server compiled: $@"

$(BINDIR)/client: $(CLIENT_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "✅ Client compiled: $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "   Compiling: $<"

# Cleanup compiled files
clean:
	@rm -rf $(BUILDDIR)
	@echo "✅ Compiled files removed"

# Full rebuild
rebuild: clean all

# Tests
test: all
	@echo "🧪 Running tests..."
	@if [ -f "$(TESTDIR)/teste_parsing_debug" ]; then \
		echo ""; \
		echo "📋 Test 1: Data Parsing"; \
		$(TESTDIR)/teste_parsing_debug; \
	fi
	@echo ""
	@echo "✅ Tests completed!"

# Help
help:
	@echo "Airline Check-in System - Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Compile client and server"
	@echo "  make clean        - Remove compiled files"
	@echo "  make rebuild      - Clean and recompile everything"
	@echo "  make test         - Run tests"
	@echo "  make help         - Show this message"
	@echo ""
	@echo "Variables:"
	@echo "  CC=$(CC)"
	@echo "  CFLAGS=$(CFLAGS)"

# Build information
info:
	@echo "📦 Build Information:"
	@echo "   Compiler: $(CC)"
	@echo "   Flags: $(CFLAGS)"
	@echo "   Source Dir: $(SRCDIR)"
	@echo "   Build Dir: $(BUILDDIR)"
	@echo "   Bin Dir: $(BINDIR)"
	@echo ""
	@echo "📝 Source Files:"
	@echo "   Company: $(COMPANY_SRC)"
	@echo "   Client: $(CLIENT_SRC)"
