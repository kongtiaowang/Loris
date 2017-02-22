<div class="row">
    <div class="col-sm-12 col-md-12">
        <div class="panel panel-primary">
            <div class="panel-body" id="panel-body">
                <form>
                     <div class="row">
                        <div class="form-group col-sm-4">
                            <label class="col-sm-12 col-md-4">Code:</label>
                            <div class="col-sm-12 col-md-8"><input type="text" id="code" onchange='calcChecksum(event)' ></div>
                        </div>
                        <div class="form-group col-sm-4">
                            <label class="col-sm-12 col-md-4">CRC-32:</label>
                            <div class="col-sm-12 col-md-8" id="cs"></div>
                        </div>
                        <div class="form-group col-sm-2">
                            <label class="col-sm-12 col-md-4">CSV to decrypt</label>
                            <div class="col-sm-12 col-md-8"><input type="file" accept=".csv" onchange='openFile(event)'></div>
                        </div>
                        <div class="form-group col-sm-8">
                            <label class="col-sm-12 col-md-2">Decrypted CSV</label>
                            <div class="col-sm-12 col-md-4"><textarea rows="30" cols="120" id="output"></textarea></div>
                        </div>
                    </div>
               </form>
            </div>
        </div>
    </div>
</div>
