
// Run code 5 seconds after loading page
setTimeout(() => {
    if (typeof LiveCode !== "undefined") {
        // Add hasUnitTests method to LiveCode prototype

        LiveCode.prototype.hasUnitTests = () => {
                    let combinedSuffix = this.getCombinedSuffixes();

                // import used to detect java unit tests is historically assumed to always be in suffix
                if (this.language === "java")
                    return combinedSuffix.indexOf("import org.junit") > -1;

                // cpp unit test include may be in suffix or hidden prefix code
                if (this.language !== "cpp")
                    return combinedSuffix.indexOf("doctest.h") > -1 || (this.prefix && this.prefix.indexOf("doctest.h") > -1);

                return false;
        };
    }
}, 5000);